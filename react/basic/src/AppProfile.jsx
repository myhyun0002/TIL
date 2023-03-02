import logo from './logo.svg';
import './App.css';
import Profile from './components/Profile';
import Avatar from './components/Avatar';

// 함수 이름은 대문자로 시작할 것
function AppProfile() {
  const handleClick = (event)=>{
    console.log(event);
    alert('버튼 클릭됨');
  };

  return (
    <>
    {
    
    /* Profile 컴포넌트를 매개변수를 이용해 재사용하였다.
      component 재사용  
    */
    }

      <button onClick={handleClick}></button>
      
      <Avatar
      image='https://images.unsplash.com/photo-1677612968800-4d9f1104d251?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80'
      isNew={true}
      />

      <Profile 
      image = 'https://images.unsplash.com/photo-1677612968800-4d9f1104d251?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80'
      name ='james'
      title = '프론트엔드 개발자'
      isNew = {true}
      />

      <Profile 
      image = 'https://images.unsplash.com/photo-1677607633013-b733166ab535?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxlZGl0b3JpYWwtZmVlZHwzfHx8ZW58MHx8fHw%3D&auto=format&fit=crop&w=1200&q=60'
      name = 'jimi'
      title = '백엔드 개발자'/>

      <Profile 
      image = 'https://images.unsplash.com/photo-1677612881943-248445e87761?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxlZGl0b3JpYWwtZmVlZHw0fHx8ZW58MHx8fHw%3D&auto=format&fit=crop&w=1200&q=60'
      name = 'yena'
      title = '풀스택 개발자'
      isNew = {true}
      />

    </>
  );
}

export default AppProfile;

