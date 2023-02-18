/*

or : ||
and : &&
not : !

우선순위 :
  and > or 

*/

const name = "Mike";
const age = 30;

if(name === 'Tom' && age > 19){
  console.log("통과");
}else{
  console.log("돌아가");
}


// Or

function sayHello(name){
  let newName = name || 'friend';     // 매개변수가 없으면 friend가 출력됨
  let msg = `Hello ${newName}`;
  console.log(msg);
}

sayHello();             
sayHello('Jane');

