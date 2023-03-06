import React from 'react';

export default function TotalCounter({total}) {
  return (
    <div className='totalCount'>
      <span>Total Count : </span>
      <span className='totalCountNumber'>{total}</span>
      {
        total > 10
        ?
        <span className='emoji'>🔥</span>
        : <span className='emoji'>❄️</span>
      }
    </div>
  );
}

