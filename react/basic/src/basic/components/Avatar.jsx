import React from 'react';

export default function Avatar({image,isNew}) {
  return (
    <div className='avatar'>
      <img 
      className='photo'
        src={image}
      alt='avatar'>
      </img>

      {/*
        {isNew && <span className='new'>NEW</span>}
        위와 같이 해도 된다. 똑같이 실행된다.      
      */}
      {
      isNew 
      ?
      <span className='new'>NEW</span> 
      : null
      }

    </div>
  );
}

