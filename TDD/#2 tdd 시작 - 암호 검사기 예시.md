# tdd 예시 - 암호 검사기
- 암호의 강도를 검사하는 코드를 작성
- 암호 규칙 3가지
  - 길이가 8글자 이상
  - 0부터 9사이의 숫자를 포함
  - 대문자 포함
- 강도
  - 세 개 모두 만족 - 강함
  - 두 개 만족 - 보통
  - 한 개 만족 - 약함
___
<br/>
<br/>

## 0. test code를 작성할 클래스 생성
___
  - 생각의 흐름
  > 1. 암호 검사기를 만들거니까 암호는 password 강도 검사니까 Strength Meter이라고 하자 
  >> - 그럼 클래스 이름을 PasswordStrengthMeter 이라고 하자.
  > 2. 일단 아무 의미 없는 test method를 하자 만들어서 test code 설정이 잘 되었는지 확인하자.
```java
public class PasswordStrengthMeterTest{
  @Test
  void name(){

  }
}
```
___
<br/>
<br/>

# 첫번째 테스트 : 모든 규칙을 충족하는 경우

- 첫번째 테스트를 뭘로 할지가 매우 중요
  - 가장 쉽거나 가장 예외적인 상황 선택
<br/>
<br/>

- 가장 쉽거나 예외적인 상황 
  - 모든 규칙 충족하는 경우
  - 모든 조건 충족하지 않는 경우

> - 생각의 흐름   
>> - 모든 조건 충족하지 않는 경우를 구현할려면 3개의 모두가 들어가 있는지 검사하는 코드가 있어야 한다.  
>> - 하지만 세 개 모두 충족하는 경우는 3개 모두를 충족한다는 것을 return 해주면 끝이다. 검사를 안해도 된다.
> - 그래서 모든 규칙 충족 하는 경우를 첫번째 테스트로 확정    

<br/>
<br/>

## 1. test code 메서드 이름을 정하자.
___
> - 생각의 흐름   
>> - 모든 조건 만족이지 meetsAllcriteria로 하고 모두 만족하면 암호를 강함으로 하기로 했으니 뒤에 Then Strong을 붙이면 좋겠네 
>> - meetsAllCriteria_Then_Strong 으로 하자.


```java
public class PasswordStrengthMeterTest{
  @Test
  void meetsAllCriteria_Then_Strong(){
    // test code 작성하는 곳
  }
}
```
<br/>
<br/>

## 2. test code 구상
___
- 간단한 test code를 어떻게 구성되야 할지 생각
```java
void meetsAllCriteria_Then_Strong(){
  PasswordStrengthMeter meter = new PasswordStrengthMeter
  ();
  값타입 결과 = meter.meter("ab12!@AB");
  assertEquals(기댓값,결과);
}
```
- 생각해야 할 것
> - PasswordStrengthMeter의 메서드인 meter의 return 값타입
>> - 약함 보통 강함을 각각 0,1,2로 할 수도 있다.
>> - 하지만 enum으로 처리해서 PasswordStrength.STRONG 으로 하면 직관적이여서 좋다.      

<br/>

```java
void meetsAllCriteria_Then_Strong(){
  PasswordStrengthMeter meter = new PasswordStrengthMeter();
  PasswordStrength result = meter.meter("ab12!@AB");
  assertEquals(PasswordStrength.STRONG,result);
}
```
___
<br/>
<br/>

## 3. test code에 있는 enum 클래스 작성
___
```java
public enum PasswordStrength{
  STRONG
}
```
- 약함(WEAK) 나 보통(NORMAL)을 작성할 수도 있지만
- test code를 통과할 수 있는 만큼만 작성
___
<br/>
<br/>

## 3-1. test code 실행
___
- 당연 에러가 난다 
- 지금은 enum 클래스만 만들었기 때문에
- PasswordStrengthMeter 클래스가 없어서 에러가 남 
- 이제는 PasswordStrengthMeter 클래스를 만들어보자.
____
<br/>
<br/>

## 4. test code에 있는 PasswordStrengthMeter 클래스 작성
___
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    return PasswordStrength.STRONG;
  }
}
```
- PasswordStrengthMeter 클래스와 meter 메서드를 만들었다.
- meter 메서드
  - test code에서 enum 클래스인 PasswordStrength를 리턴하자고 결정했으므로 reuturn 값을 PasswordStrength로 했다.

> ### 중요한 점
> ```java
> void meetsAllCriteria_Then_Strong(){
>  PasswordStrengthMeter meter = new PasswordStrengthMeter
>  ();
>  PasswordStrength result = meter.meter("ab12!@AB");
>  assertEquals(PasswordStrength.STRONG,result);
>}
> ```
>> - 위 test code를 통과하기 위해선 meter 메서드가 그냥 >> PasswordStrength.Strong을 직접 return 해주면 된다.
> - 따라서 PasswordStrengthMeter의 meter 메서드를 아래와 같이 작성했다.
>```java
>   public PasswordStrength meter(String s){
>    return PasswordStrength.STRONG;
>  }
> ```
> ## test code를 통과할 수 있는 만큼만 작성
___
<br/>
<br/>

## 4-1. test code 실행
```java
@Test
void meetsAllCriteria_Then_Strong(){
  PasswordStrengthMeter meter = new PasswordStrengthMeter();

  PasswordStrength result = meter.meter("ab2!@AB");
  assertEquals(PasswordStrength.STRONG, result)

  PasswordStrength result2 = meter.meter("abc1!add");
  assertEquals(PasswordStrength.STRONG, result2)

}
```
- 세 개의 조건을 만족하는 result2를 추가하여 test를 돌렸더니 잘 통과했다.
- 당연한 결과다 어떤 String이 들어오든 meter 메서드는 PasswordStrength.Strong 값을 return 하기 때문에
___
<br/>
<br/>

