export default function Profile({image,title,name,isNew}){
  return (
    <div className='profile'>
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
      
      <h1>{name}</h1>
      <p>{title}</p>
    </div>
  );
}
