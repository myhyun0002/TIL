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
  }

}

superman.fly();
superman.run();
superman.sayHello();




// 객체의 별명을 하나 더 만든다.
let man = superman;
man.name = "man";
man.sayHello();


