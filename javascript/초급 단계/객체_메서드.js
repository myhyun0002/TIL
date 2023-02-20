/*
  메서드 : 객체 안에 있는 함수를 의미
*/

const superman = {
  name: 'superman',
  age: 30,

  fly : function(){
    console.log("날라간다.");
  },

  // 위의 함수를 줄여서 이렇게도 작성할 수 있다.
  run(){        
    console.log("날라간다.");
  },

  // 객체 안에 있는 변수를 쓰고 싶다면 this 사용
  sayHello(){
    console.log(`Hello ${this.name}`);
  },

  // 객체를 선언하는 방법 중 아래와 같이 화살표 함수로 선언할 수도 있는데
  // 화살표 함수로 선언할 경우 이 안에 들어가 있는 this는 객체를 가리키는게 아닌 window를 가리킨다.
  // 따라서 객체를 선언할 때는 화살표 함수를 가급적 사용하지 않는 것이 좋다.
  sayThis : () => {
    console.log(this);
  }

}

superman.fly();
superman.run();
superman.sayHello();




// 객체의 별명을 하나 더 만든다.
let man = superman;
man.name = "man";
man.sayHello();




const user = {
  [1 + 4] : 5,
  ["안녕" + "하세요"] : "Hello"
}

console.log(user);