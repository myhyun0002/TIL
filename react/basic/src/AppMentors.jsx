import React, { useState } from 'react';

export default function AppMentors() {
  const [person,setPerson] = useState(intialPerson);
  const handleUpdate = () => {
    const prev_name = prompt("누구의 이름을 바꾸고 싶은가요?");
    const current_name = prompt("이름을 무엇으로 바꾸고 싶은가요?");
    setPerson((prev) =>  
    ({...prev, mentors : prev.mentors.map((mentor) => {
      if(mentor.name === prev_name) {
        return {...mentor,name : current_name};
      }
      return mentor;
    })}
    ));
  }

  const handleDelete = () => {
    const delete_mentor_name = prompt("삭제할 멘토 이름이 뭔가요");

    setPerson((prev) => ({...prev, mentors : prev.mentors.filter((mentor) => mentor.name !== delete_mentor_name)}
    ));
  }

  const handleAdd = () => {
    const add_mentor_name = prompt("추가할 멘토 이름이 뭔가요");
    const add_mentor_title = prompt("추가할 멘토 title이 뭔가요");
    setPerson((prev) => ({...prev,mentors : [...prev.mentors,{name : add_mentor_name,title : add_mentor_title}]}
    ));
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

const intialPerson = {
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

