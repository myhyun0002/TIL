import React, { useState } from 'react';

/*
  react의 철학 : 모든 ui의 변경은 상태 변경으로부터 발생
  근데 입력창 같은 경우에는 내부적으로 상태가 변화가 없어도 키보드로 치면 그 칸에 그대로 적히다
  즉 react에서 상태 변경이 없는 데 ui는 상태 변경이 일어나는 것이다

  따라서 이걸 입력창에 글자를 쓰면 react에서도 그 값을 저장을 계속 해줘야 한다.
*/
export default function AppForm() {
  const handleSubmit = (e) => {

    // e.preventDefault()를 하지 않으면 submit 버튼을 누를 때 마다 새로고침이 일어난다.
    // 그럼 버튼을 누르면 새로고침이 되서 적었던 글들이 없어진다.
    
    // 밑에껄 해주면 새로고침이 안되고 그냥 버튼만 눌러진다. 
    e.preventDefault();
  };

  const [form,setForm] = useState({name:'',email:''});
  const handleChange = (e) => {
    console.log(e.target);
    const {name,value} = e.target;
    setForm({...form,[name] : value});
  }

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <label htmlFor="name">이름:</label>
        <input type = 'text' id = 'name' name = 'name' value={form.name} 
        onChange = {handleChange}/>
        <label htmlFor='email'>이메일:</label>
        <input type = 'email' id = 'email' name = 'email' value = {form.email} 
        onChange = {handleChange}/>
        <button>Submit</button>
      </form>
    </div>
  );
}

