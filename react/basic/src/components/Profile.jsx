import Avatar from './Avatar';

export default function Profile({image,title,name,isNew}){
  return (
    <div className='profile'>
      
      <Avatar 
      image={image}
      isNew={isNew}
      />
      
      <h1>{name}</h1>
      <p>{title}</p>
    </div>
  );
}
