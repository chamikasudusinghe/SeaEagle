var listRef = firebase.database().ref('boat-list');

var boatRef = firebase.database().ref('boat');

document.getElementById('boatFrom').addEventListener('submit', submitForm);

function submitForm(e){
  e.preventDefault();

  var id = getInputVal('id');
  var count = getInputVal('count');
  var begin = getInputVal('begin');
  var end = getInputVal('end');

  saveMessage(id, count, begin, end);
  saveBoat(id, count, begin, end);

  document.querySelector('.alert').style.display = 'block';

  setTimeout(function(){
    document.querySelector('.alert').style.display = 'none';
  },3000);

  document.getElementById('boatFrom').reset();
}

function getInputVal(id){
  return document.getElementById(id).value;
}

function saveList(id, count, begin, end){
  var newListRef = listRef.push();
  newListRef.set({
    id: id,
    count:count,
    begin:begin,
    end:end,
  });
}

function saveBoat(id, count, begin, end){
  boatRef.set({
    id: id,
    count:count,
    begin:begin,
    end:end,
  });

}
