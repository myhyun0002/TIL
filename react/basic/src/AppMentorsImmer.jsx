import React, { useReducer, useState } from 'react';
import personReducer from './reducer/person-reducer';
import {useImmer} from 'use-immer';

/*
  기존 AppMentors 파일은 useState로 작성되었는데
  이걸 Immer로 작성해본다.
*/

export default function AppMentorsImmer() {
  //const [person,setPerson] = useState(intialPerson);
  const [person,updatePerson] = useImmer(initialPerson);

  const handleUpdate = () => {
    const prev = prompt("누구의 이름을 바꾸고 싶은가요?");
    const current = prompt("이름을 무엇으로 바꾸고 싶은가요?");

    // setPerson((prev) =>  
    // ({...prev, mentors : prev.mentors.map((mentor) => {
    //   if(mentor.name === prev_name) {
    //     return {...mentor,name : current_name};
    //   }
    //   return mentor;
    // })}
    // ));

    updatePerson((person)=>{
      const mentor = person.mentors.find((m) => m.name === prev);
      mentor.name = current;
    }
    );
  }

  const handleDelete = () => {
    const name = prompt("삭제할 멘토 이름이 뭔가요");

    // setPerson((prev) => ({...prev, mentors : prev.mentors.filter((mentor) => mentor.name !== delete_mentor_name)}
    // ));

    updatePerson((person) => {
      const index = person.mentors.findIndex((m) => m.name === name);
      person.mentors.splice(index,1);
    })
  }

  const handleAdd = () => {
    const name = prompt("추가할 멘토 이름이 뭔가요");
    const title = prompt("추가할 멘토 title이 뭔가요");
    // setPerson((prev) => ({...prev,mentors : [...prev.mentors,{name : add_mentor_name,title : add_mentor_title}]}
    // ));

    updatePerson((person) => {
      person.mentors.push({name,title});
    });
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

