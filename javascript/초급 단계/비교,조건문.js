// === : type까지 비교해서 받는지 본다.
const a = 1;
const b = "1";

// true     (실제 값만 비교)
console.log(a == b);

//false     (값과 타입까지 비교)
console.log(a === b);




// 비교연산자 if

const age = 19;

if(age > 19){
  console.log('환영합니다.');

} else if(age === 19){
  console.log("수능 잘치세요");
}else{
  console.log("안녕히 가세요");
}