# symbol
```javascript
// 다른 개발자가 만들어 놓은 객체
const user = {
  name : 'Mike',
  age : 30
}

// 내가 작업
const showName = Symbol('show name');
user[showName] = function(){
  console.log(this.name);
}

// 사용자가 접속하면 보는 메세지

for(let key in user){
  console.log(`His ${key} is ${user[key]}.`);
}

/*
His name is Mike.
His age is 30.
*/
```
결과를 보면 Symbol로 정의한 함수는 출력이 되지 않는 것을 볼 수 있다.      
다른 개발자가 만들어 놓은 객체에서 사용자에게 보여주는 형식이 정해져 있을  때         
내가 따로 객체에 뭔가를 만들어서 사용하고 싶은데 그렇게 되면 사용자에게 보여주는 형식도 변화하게 되니       
형식 변화 없이 쓰고 싶을 때 symbol을 사용한다.
