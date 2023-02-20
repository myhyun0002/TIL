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


/*

  js는 파일이 실행되기 전에 함수 선언식을 전부 미리 저장해놓는다.
  따라서 아래에 선언된 함수를 미리 써도 동작이 된다.

  아래와 같이 함수가 선언 되기 전에 호출되도 실행이 된다.
*/

sayBye();

function sayBye(){
  console.log("Bye");
}


/*
  화살표 함수
*/

showErrors()

// 일반 함수
// 일반 함수는 선언 전에 호출해도 에러가 안난다.
function showErrors(){
  console.log('errors');
}

// 화살표 함수
// 화살표 함수는 선언 전에 호출하면 에러난다.
let showErrors_arrowFuction = () => {
  console.log('showErrors');
}

showErrors_arrowFuction();


// sayHello 함수의 화살표 버전
const sayHello_arrowFuction = (name) => {
  const msg = `Hello ${name}`;
  console.log(msg);
}

sayHello_arrowFuction('Jane');



// add 함수의 화살표 버전
const add_arrowFuction = (num1,num2) => {
  return num1 + num2;
}

console.log(add_arrowFuction(1,3));

// return문은 중괄호가 아닌 소괄호를 써서 return 없이도 가능하다.

const add_arrowFuction_return_none = (num1,num2) => (
  num1 + num2
)

console.log(add_arrowFuction_return_none(1,4));