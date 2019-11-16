function autoHeight(el) {
  el.style.height = getComputedStyle(el).width;
}
function autoHeightAll() {
  youtube = document.querySelector('#youtube');
  autoHeight(youtube);
  devNote = document.querySelectorAll('#dev_note > *');
  devNote.forEach(element => {
    autoHeight(element)
  });
}

addEventListener('resize', autoHeightAll)

autoHeightAll()