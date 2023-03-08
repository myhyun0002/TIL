import React, { useReducer, useState } from 'react';
import personReducer from './reducer/person-reducer';

export default function AppMentors() {
  //const [person,setPerson] = useState(intialPerson);

  /*
    userReducer
    사용하면 로직은 외부에 있고 외부에 있는 로직을 가지고 와서 
    component에는 해당 로직을 불러와서 사용만 하면 된다
    훨씬 깔끔해진다.
  */

  const [person,dispatch] = useReducer(personReducer,initialPerson);
  const handleUpdate = () => {
    const prev = prompt("누구의 이름을 바꾸고 싶은가요?");
    const current = prompt("이름을 무엇으로 바꾸고 싶은가요?");

    /*
      useState로 할 때는 아래와 같이 한다.
    */
    // setPerson((prev) =>  
    // ({...prev, mentors : prev.mentors.map((mentor) => {
    //   if(mentor.name === prev_name) {
    //     return {...mentor,name : current_name};
    //   }
    //   return mentor;
    // })}
    // ));

    /*
      useReducer로 할 때는 아래 코드 사용
    */
   dispatch({type : 'update',prev,current});
  }

  const handleDelete = () => {
    const name = prompt("삭제할 멘토 이름이 뭔가요");

    // setPerson((prev) => ({...prev, mentors : prev.mentors.filter((mentor) => mentor.name !== delete_mentor_name)}
    // ));

    dispatch({type : 'deleted',name});
  }

  const handleAdd = () => {
    const name = prompt("추가할 멘토 이름이 뭔가요");
    const title = prompt("추가할 멘토 title이 뭔가요");
    // setPerson((prev) => ({...prev,mentors : [...prev.mentors,{name : add_mentor_name,title : add_mentor_title}]}
    // ));
    dispatch({type : 'added',name,title});
  }

  return (
    <div>
      <h1>
        {person.name}는 {person.title}
      </h1>
      <ul>
        {person.mentors.map((mentor,index) => (
          <li key = {index}>
            {mentor.name} ({mentor.title})
          </li>
        ))}
      </ul>

      <button onClick={handleUpdate}>멘토 이름 바꾸기</button>

      <button onClick={handleAdd}>멘토 추가하기</button>

      <button onClick={handleDelete}>멘토 삭제하기</button>

    </div>
  );
}

const initialPerson = {
  name : '엘리',
  title: '개발자',
  mentors:[{
    name: '밥',
    title: '시니어 개발자'
  },
  {
    name: '제임스',
    title: '시니어 개발자'
  }]
};

