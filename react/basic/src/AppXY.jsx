import React, { useState } from 'react';
import './AppXY.css';

export default function AppXY() {
  // x와 y가 좌표로 묶어서 같은 객체로 설정 {x:0,y:0} 이렇게 설정
  const [xy,setXY] = useState({x:0,y:0});
  const handleMouseMove = (e) => {
    setXY({x: e.clientX, y: e.clientY});
  }

  // 만약 y축은 가만히 있고 x축만 움직이게 하고 싶다면 아래와 같이 한다..
  const handleMouseMove_x = (e) => {
    setXY(prev => ({x : e.clientX, y: prev.y}));
  }

  // 만약 z축 까지 있는 상태에서 x만 변화하고 싶게 하고 싶다면
  const handleMouseMove_x_yz = (e) => {
    setXY((prev) => ({...prev, x : e.clientX}));
  }

  let point_style = {
    transform: `translate(${xy.x}px, ${xy.y}px)`
  }

  return (
    <div className='container' onMouseMove={(e) => {handleMouseMove_x_yz(e)}}>
      <div className="pointer" style = {point_style}/>
    </div>
  );
}

