// 전역
let msg = "welcome";

function sayHello(name) {

  // 지역 변수
  let msg = "hello";
  console.log(msg + ' ' + name );
}

sayHello("이름");     // 지역 변수가 출력이 된다.
console.log(msg);    // 전역 변수가 출력이 된다.

