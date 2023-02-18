const age = 21;

switch(age){
  case 20:
      console.log("20 입니다.");
  case 19:
      console.log("19입니다.");
  case 18:
      console.log("18입니다.");
}


/*
주의할 건 위와 같이 짤 경우
case 19에서 true가 뜨고 19를 출력한 다음 밑에 꺼인 18도 출력이 된다.
true 가 발생한 순간 밑에 계속 true가 된다. 따라서 break를 써줘야 한다.

*/

switch(age){
  case 20:
      console.log("20 입니다.");
      break;
  case 19:
      console.log("19입니다.");
      break;
  case 18:
      console.log("18입니다.");
      break;
  default:
      console.log("없습니다");
}