/*
  객체

  중괄호를 사용
  key:value 형식임
*/

const superman = {
  name : 'clark',
  age : 30,
}

// 조회
console.log(superman);
console.log(superman.name);
console.log(superman['name']);

// 추가
superman.hairColor = 'black';
superman.name = 'Jane';
superman['age']  = 41;
console.log(superman);

// 삭제
delete superman.hairColor;
console.log(superman);


// 객체를 형성하는 함수를 선언
function makeObject(name,age){
  return {    
    name : name,    // name이라는 key에는 매개변수로 받아온 name을 사용
    age : age,
    hobby : 'football'
  }
}

const Mike = makeObject('Mike',30);
console.log(Mike);


// 객체를 형성하는 함수 축약형
function makeObject_short(name,age){
  return {
    name,
    age,
    hobby: 'soccer'
  }
}

const Mike_short = makeObject('Mike',30);
console.log( Mike_short);




/*
  in을 이용해 객체에 key가 있는지 확인
*/

function isAdult(user){

  if(user.age < 20){
    return false;
  }
  return true;
}

const James = {
  name: "Mike",
  age : 20
}

const Jany = {
  name : "Jany"
}
console.log(isAdult(James));    // true가 나와야 됨
console.log(isAdult(Jany));     // false가 나와야 되는데 true가 나옴

/*
  jany 같은 경우는 age key가 없어서 user.age < 20 비교가 안되는데 true가 나왔다. 왜일까? 
  jany인 경우 user.age는 undefined를 반환하기 때문에 if(undefined < 20) 이면 안에께 false가 되서 결국 if문을 실행 안하고
  return true가 항상 되는 것이다.
  이럴 때 쓰는게 in 함수이다.

  객체에 해당 key값이 있는지 확인하는 문구를 추가해보자.

*/

function isAdult_fix(user){

  if(user.age < 20 || !('age' in user)){     // age라는 key가 없으면 false가 출력되도록 한다.
    return false;
  }
  return true;
}

console.log(isAdult_fix(Jany));



/*
  for in 문
*/

const Mike_for = {
  name :"mike",
  age : 30
}


// 이때 x에는 Mike_for 객체에 있는 key 값을 반환한다.
for(x in Mike_for){
  console.log(x);
}

console.log();

// value를 가져오고 싶다면 아래와 같이 하면 된다.
for(x in Mike_for){
  console.log(Mike_for[x]);
}