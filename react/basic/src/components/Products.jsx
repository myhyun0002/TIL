import React, { useState,useEffect } from 'react';

export default function Products() {
  const [products,setProducts] = useState([]);
  const [checked,setChecked] = useState(false);
  const handleChange = () => {setChecked((prev) => !prev)};

  /*
    useState는 초기화 되었다가 변경이 되면 component를 처음부터 다시 시작한다.
    따라서 만약 아래와 같이 하면 무한루프에 빠진다.

  fetch('data/products.json')
  .then((res)=>res.json())
  .then((data) => {
    console.log("잘 들어왔습니다!");
    setProducts(data);
  });

  fetch로 data/products.json 안에 있는 데이터를 가지고 온 게 res에 들어오고
  해당 데이터는 Json파일 이니까 json()으로 분석하고 그 다음 그 안에 있는 데이터를 사용할 수 있다.
  해당 데이터가 data 안에 들어있고 data는 배열이니까 바로 setProducts(data)해서 products 변수에 넣어준다.
  그러면 위에 const [products,setProducts] 쪽에 변경이 일어났으니 react는 다시 해당 페이지를 실행한다.
  
  그럼 위와 같은 행동을 또하고 또 setProducts(data)를 해주니 무한루프에 빠진다

  이걸 방지하는 것이 useEffect() 이다. component에서 딱 한번만 호출되기를 원할 때 useEffect() 사용

  useEffect()에서 첫번째는 원하는 callback 함수를 넣고 그 뒤에는 빈 배열을 넣으면
  callback 한 후 다시 실행하지 않는다. 딱 한번만 실행하게 된다.


  만약 useEffect() 맨 마지막에 [checked]를 넣으면 checked가 변경될 때마다 useEffect이 실행된다.
  */

  useEffect(() =>{
    fetch(`data/${checked ? 'sale_' : ''}products.json`)
    .then((res)=>res.json())
    .then((data) => {
      console.log("잘 들어왔습니다!");
      setProducts(data);
    });

    // 해당 component가 없어질 때 cache나 소켓을 비우는 역할을 한다.
    return () => {
      console.log('깨끗하게 청소하는 일들을 합니다.');
    } 
  },[checked]);

  return (
    <div>
      <input id='checkbox' type = "checkbox" value = {checked} onChange={handleChange} />
      <label htmlFor='checkbox'>Show Only 🔥 Sale</label>
      <ul>

        {/* 
          map을 이용해서 자식 요소를 만드는 경우에는 
          고유한 key값을 넣어줘야 한다
          key = {product.id}처럼 말이다.
        */}
        {products.map((product)=>(
          <li key={product.id}>
            <article>
              <h3>{product.name}</h3>
              <p>{product.price}</p>
            </article>
          </li>
        ))}
      </ul>
    </div>
  );
}

