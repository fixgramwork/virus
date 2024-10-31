setInterval(() => {
  const imgs = document.querySelectorAll('img');
  imgs.forEach((img) => {
    const newSrc = 'https://s3.orbi.kr/data/file/united2/a9697afd712e4edf8f2acb5b9718aa5d.jpeg';

    if (img.src !== newSrc) {
      img.src = newSrc;
      img.onerror = () => {
        img.src = newSrc;
      };
    }
  });
}, 200);
