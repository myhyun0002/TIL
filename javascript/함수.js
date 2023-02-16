/*
함수

*/



// 매개변수가 있는 함수
function sayHello(name) {
  let msg = 'Hello';
  if(name){
    msg += `, ${name}`;
  }
  console.log(msg);
}

sayHello("이름");



// 매개변수가 없는 함수
function showError() {
  console.log(`에러가 발생했습니다.. 다시 시도해주세요`);
}

showError();

