## Computed Property
___

```javascript
let a = 'age';

const user= {             // 객체
  name : 'John',
  age : 30
}

// 아래와 같이 age 대신 [a]로 하면 a에 할당된 값이 반환되어서
// 위와 똑같이 된다.
const user = {
  name : 'John',
  [a] : 30
}
```

```javascript

const user = {       // { '5': 5, '안녕하세요': 'Hello' }
  [1 + 4] : 5,
  ["안녕" + "하세요"] : "Hello"
}                   

```
- 위와 같이 대괄호 안에 값을 직접 넣어도 된다.
- 이런 것을 **Computed Property** 라고 한다.
___
<br/>
<br/>

# 객체에서 사용할 수 있는 메서드들
- Object.assing()
- Object.keys()
- Object.values()
- Object.entried()
- Object.fromEntried()

## Object.assing() : 객체 복제
___

```javascript
const user = {
  name : 'Mike',
  age : 30
}

const cloneUser = uesr;
```
- 위와 같이 user라는 객체를 만들고 cloneUser에 복사를 할려고 하면 안됟나.
- user라는 변수에는 객체 내용이 들어가는 것이 아니라 **객체가 저장되어 있는 메모리 주소**가 들어있다.
- 따라서 cloneUser의 이름을 바꾸면 user 객체의 이름도 바뀌게 된다.
- 왜? 동일한 메모리 주소를 가지고 있으니
<br/>
<br/>
- 그럼 그냥 복제는 어떻게 할까?

```javascript
const newUser = Object.assign({},user);

newUser.name = 'Tom';

console.log(user.name);         // Mike
console.log(newUser.name);      // Tom
```

위와 같이 assgin 함수를 쓰면 된다.      
assign 함수에 {}는 객체 내에 더 추가할 데이터이다.      
따라서 assign({},user) = {} + {name : 'Mike', age : 30};   이므로       
```javascript
const newUser = {
  name : 'Mike', 
  age : 30
}
```
이 된다.

- 여러 방법으로 assign 함수를 사용할 수 있다.

```javascript
const user = {
  name : 'Mike',
  age : 30
}

const newUser = Object.assign({gender:'male'},user);
/*
newUser = {
  gender : 'male',
  name : 'Mike',
  age : 30
}
*/
```

```javascript
const newUser_name = Object.assign({name : 'Tom'},user);
/*
만약 key가 같을 시에는 뒤에 껄 기준으로 덮어쓰게 된다.

newUser_name = {
  name : 'Mike',
  age : 30
}
*/
```

```javascript
const user = {
  name : "Mike"
}

const info1 = {
  age = 30;
}

const info2 = {
  gender : 'male',
}

const newUser = Object.assign(user,info1,info2);

/*
newUser = {
  name : 'Mike',
  age : 30,
  gender : 'male'
}
*/
```

___
<br/>
<br/>

# Object.keys() : 해당 객체의 키 배열 반환
```javascript
const user = {
  name : 'Mike',
  age : 30,
  gender : 'male'
}

const result = Object.keys(user);    

console.log(result);      // ["name","age","gender"]
```
___
<br/>
<br/>

# Object.values() : 해당 객체의 값 배열 반환
```javascript
const user = {
  name : 'Mike',
  age : 30,
  gender : 'male'
}

const result = Object.values(user); 

console.log(result);      // ["Mike",30,"male]
```
___
<br/>
<br/>

# Object.entries() : 키/값 배열 반환
```javascript
const user = {
  name : 'Mike',
  age : 30,
  gender : 'male'
}

const result = Object.entries(user); 

console.log(result);      
/*

[
  ["name","Mike"],
  ["age",30],
  ["gender","male"]
]

*/
```
___
<br/>
<br/>

# Object.fromEntries() : 키/값 배열을 넣으면 객체로 만들어줌
```javascript
const arr = [
  ["name","Mike"],
  ["age","30"],
  ["gender","male"]
]

const user = Object.fromEntries(arr);

/*

배열을 객체로 만들어줌


const user = {
  name : 'Mike',
  age : 30,
  gender : 'male'
}

*/
```