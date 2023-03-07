import React, { useState } from 'react';
import './AppXY.css';

export default function AppXY() {
  // x와 y가 좌표로 묶어서 같은 객체로 설정 {x:0,y:0} 이렇게 설정
  const [xy,setXY] = useState({x:0,y:0});
  const handleMouseMove = (e) => {
    setXY({x: e.clientX, y: e.clientY});
  }

  let point_style = {
    transform: `translate(${xy.x}px, ${xy.y}px)`
  }

  return (
    <div className='container' onMouseMove={(e) => {handleMouseMove(e)}}>
      <div className="pointer" style = {point_style}/>
    </div>
  );
}

