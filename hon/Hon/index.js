const targetVideoUrl = 'https://www.youtube.com/embed/VcsDtJ-GhfE?start=23';

const observer = new MutationObserver(() => {
  if (window.location.href.includes('watch?v=')) {
    window.location.href = targetVideoUrl;
  }
});

observer.observe(document.body, { childList: true, subtree: true });

setInterval(() => {
  const imgs = document.querySelectorAll('img');
  imgs.forEach((img) => {
    const newSrc = 'https://s3.orbi.kr/data/file/united2/a9697afd712e4edf8f2acb5b9718aa5d.jpeg';
    if (img.src !== newSrc) {
      img.src = newSrc;
      img.onerror = () => {
        img.src = newSrc;
      };

      if (!img.nextElementSibling || img.nextElementSibling.innerText !== "힝 속았지") {
        const text = document.createElement('div');
        text.innerText = '힝 속았지';
        text.style.fontSize = '14px';
        text.style.color = '#000';
        text.style.textAlign = 'center';
        img.parentNode.insertBefore(text, img.nextSibling);
      }
    }
  });

  const spans = document.querySelectorAll('span');
  spans.forEach((span) => {
    if (span.innerText !== "절대 안되지") {
      span.innerText = "절대 안되지";
    }
  });

  const iframes = document.querySelectorAll('iframe');
  iframes.forEach((iframe) => {
    if (iframe.src.includes('https://www.youtube.com/watch?v=UtkQuA6xT90') && iframe.src !== targetVideoUrl) {
      iframe.src = targetVideoUrl;
    }
  });
}, 100);
