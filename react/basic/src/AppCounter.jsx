import React,{useState} from 'react';
import './App.css'
import Counter from './components/Counter';
import TotalCounter from './components/TotalCounter';

export default function AppCounter() {
  const [count,setCount] = useState(0);
  const handleClick = () => setCount(prev => prev + 1);
  return (
    <div>
      <TotalCounter
      total = {count}
      />

      {/* 
        Counter 또한 매개변수로 total과 onclick 두개의 매개변수를 받는다.
      */}
      
      <Counter 
      total = {count} 
      onClick={handleClick}
      />

      <Counter 
      total = {count} 
      onClick={handleClick}
      />


    </div>
  );
}

