import logo from './logo.svg';
import './App.css';

// 함수 이름은 대문자로 시작할 것
function AppJSX() {
  const name = '엘리';
  const list = ['우유','딸기','바나나'];
  return (
    // 여기에는 jsx 문법을 쓰면 되는데 html과 거의 유사 
    /*
    그러나 3가지 주의 사항이 있음
      1. 최종 태그는 하나만 반환
        - 그래서 여러가지 태그를 사용하기 위해서는 빈 태그로 묶어서 한다.
      2. html에서는 class를 사용하지만 jsx는 className을 사용
      3. html 문법을 사용하고 있지만 이 파일 자체는 js다. 따라서 js도 사용 가능하다.
        - 단, js를 쓸려면 중괄호를 써야 한다.
    */


    // 1번 주의사항 (최종 반환 태그는 하나여야 한다. 여러 태그를 쓰고 싶다면 부모 태그 사용)
    <>
      {/* 2번 주의사항 (class대신 className 사용)*/}
      <h1 className='orange'>{`Hello! ${name}`}</h1>
      <h2>hello</h2>
      {/* 3. 주의사항 (js를 쓸려면 중괄호를 사용) */}
      <h3>{name}</h3>
      <ul>
        {
          list.map((item) => (
            <li>{item}</li>
          ))
        }
        <li>우유</li>
        <li>딸기</li>
      </ul>
      
    </>
    
  );
}

export default AppJSX;
