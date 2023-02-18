/*
  배열 

*/

let students = ['철수','영희','영수'];

console.log(students[0]);             // 철수

students[0] = '민재';

console.log(students[0]);             // 민재



/*
  배열 안에는 
  문자,숫자,boolean,함수,객체
  다양한 것을 넣을 수 있다.
*/

let arr = [
  '민수',
  3,
  false,
  {
    name : 'jane',
    age : 30
  },
  function(){
    console.log('배열 안에 있는 함수');
  }
]

console.log("\n");

for(let i = 0 ; i < arr.length;i++){
  console.log(arr[i]);
}


/*
  배열의 메서드

  push() : 배열 끝에 요소 추가
  pop() : 배열 끝에 요소 제거

  unshift() : 배열 맨 앞에 요소 추가
  shift() : 배열 맨 앞에 요소 삭제  

*/

let date = [1,2,3,4];

// push
date.push(5);
console.log(date);        // [1,2,3,4,5]

// pop()
date.pop();
console.log(date);        // [1,2,3,4]

// unshift
date.unshift(0);
console.log(date);        // [0,1,2,3,4]

// shift
date.shift();
console.log(date);        // [1,2,3,4]



// 여러개를 추가할 수도 있다.

// push (여러개)
date.push('금','토','일');    
console.log(date);        // [1,2,3,4,'금','토','일']

// unshift (여러개)
date.unshift('월','화','수');
console.log(date);        // ['월','화','수',1,2,3,4,'금','토','일']


console.log();





// array for문 (2가지 방법)


// for 첫번째 방법
for(let day of date){
  console.log(day);
}

console.log();

// for 두번째 방법
for(let i = 0 ; i < date.length ; i++){
  console.log(date[i]);
}
