/*
함수

*/



// 매개변수가 있는 함수
function sayHello(name) {
  let msg = 'Hello';
  if (name) {
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


// 매개변수 default

function sayHello(name = `friend`) {   // 매개변수가 없으면 name = 'friend
  let msg = `Hello ${name}`;
  console.log(msg);
}

sayHello();



// return 반환 함수

function add(num1,num2){
  return num1 + num2;
}

const result = add(1,3);
console.log(result);

/*
  return이 없는 void 함수도 undefined를 항상 반환함.
*/


/*
  하나의 함수에 하나의 작업만 하도록 설계
*/
