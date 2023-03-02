import React, { useState } from 'react';

export default function Counter() {
  /*
    react에서 외부 변수를 사용하고 싶으면 useState를 써야 한다
    number : 변수
    setNumber: 변수를 변화시키는 함수

    setNumber가 호출될 때마다 useState가 갱신이 되어서 number도 같이 갱신
  */
  const [number,setNumber] = useState(0);

  return (
    <div className='counter'>
      <p className='number'>{number}</p>
      {/* 
        밑에 onClick 같은 함수를 call back 함수라고 한다
        call back 함수 : 파라미터에 함수가 들어있는 함수를 말함
        onClick을 보면 ()=>{} 이렇게 화살표 함수가 들어있는 것을 볼 수 있다.
        따라서 onClick은 call back 함수이다.

        call back 함수인 경우 실행이 되면 안에 있는 것들이 일단 snapshot으로 찍히고 
        찍힌 당시에 변수들을 기준으로 계산이 된다
        따라서 onClick이 실행되었을 때의 number값이 0이면 setNumber(number+1)에서
        number 값은 항상 0이 된다.
        
        그런데 react에서는 call back 함수에 이전 state를 저장할 수 있는 기능이 있다

        그게 setNumber((prev)=>prev+1) 하는 것이다 그러면 prev에 바로 전 상태가 저장이 되었다가
        사용하게 된다
      */}
      <button className='button' onClick={()=>{
        setNumber(number+1);
        setNumber((prev) => prev + 1);
        setNumber((prev) => prev + 1);
        setNumber((prev) => prev + 1);
      }}>Add +</button>
    </div>
  );
}

