# TDD
- 테스트 코드를 먼저 짠 후 테스트 코드에서 쓰인 클래스와 메서드를 하나씩 
만들어 감     

참고로 gradle 프로젝트 진행 중이므로 gradle 프로젝트 설정에 맞춰 정리
- src/main/java
  - 실제 배포 코드가 들어있는 곳
- src/test/java
  - test 코드를 작성하는 곳


<br/>
<br/>

## 예시
___
- 덧셈 기능을 짠다고 가정하자.
1. 처음엔 src/test/java 에서 CalculatorTest.java 파일을 만든다.
    - 이 파일은 덧셈 기능을 test를 하기 위한 test code를 작성하는 파일이다.
2. 내가 덧셈 코드를 짜기 위한 클래스 이름, 메서드 이름, 매개변수 등등을 생각한다.
```java
public class CalculatorTest{
  @Test
  void plus() {
    int result = Calculator.plus(1,2);
    assertEquals(3,result);
  }
}
```
>  - 위의 코드는 내가 덧셈을 구현해서 배포하기 위해서 생각해낸 test code다.
>>  - 생각의 흐림   
>> 1. 덧셈을 수행할 클래스 이름을 난 Calculator 라고 짓겠어.
>> 2. 해당 클래스 안에서 실제로 덧셈을 할 메서드 이름을 plus라고 하겠어.
>> 3. 덧셈을 할려면 최소 두개의 파라미터가 있어야 하니까 일단 파라미터는 두개 !
>> 3. plus 메서드는 일단은 정적 메서드로 하겠어.     
>> 4. 내가 예상한 값과 실제 계산한 값이 같은지 assertEquals()를 통해 확인
4. 위의 코드는 test code고 실행시키면 당연 에러가 난다. 왜? 실질적인 Calculator 클래스와 plus 메서드를 만들지 않았으니까.
5. 이제 test code에 적었던 클래스와 메서드를 src/test/java 폴더에 만든다.
```java
public class Calculator{
  public static int plus(int a1, int a2){
    return a1 + a2;
  }
}
```     

  - src/main/java 폴더에는 실제로 배포할 코드를 작성한다.
  - src/test/java 폴더에 먼저 작성 후 test code가 잘 작동하면 그 다음 src/main/java로 옮긴다.
      - 이렇게 하면 배포 폴더에 있는 코드는 test가 끝난 code만 있으니 완성되지 않으 코드가 배포되는 것을 미리 방지할 수 있다.

6. test code가 정상 작동하면 src/main/java폴더로 옮긴다.
___   

- 위의 test code를 작성할 때 생각의 흐름은 우리가 이전에 test code를 생각 안하고 만들었을 때와 똑같은 생각의 흐름이다.
### tdd는 다만 이 과정을 test code로 작성을 먼저 한 뒤 구현을 하는 행위를 말한다.
___
<br/>
<br/>


