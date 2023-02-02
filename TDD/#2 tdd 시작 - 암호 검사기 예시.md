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

# test code를 작성할 클래스 생성
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

# 두번째 테스트 : 길이만 8글자 미만이고 나머지 조건 충족하는 경우

## 1. 두번째 test code 작성
___
> - 생각의 흐름   
>> - 모든 조건 만족이지 meetsAllcriteria로 하고 모두 만족하면 암호를 강함으로 하기로 했으니 뒤에 Then Strong을 붙이면 좋겠네 
>> - meetsAllCriteria_Then_Strong 으로 하자.


```java
public class PasswordStrengthMeterTest{
  @Test
  void meetsAllCriteria_Then_Strong(){
    // 첫번재 테스트 수행
  }

  @Test
  void meetsOtherCriteria_except_for_Length_Then_Normal(){
    PasswordStrengthMeter meter = new PasswordStrengthMeter();
    PasswordStrength result = meter.meter("ab12!@A");
    assertEquals(PasswordStrength.NORMAL,result);
  }
}
```
<br/>
<br/>

## 2. enum 클래스 수정
___
```java
public enum PasswordStrength{
  NORMAL,STRONG
}
```
- 두개만 만족하니 강도는 NORMAL이다.
- test code가 에러 안날 정도만 작성
___
<br/>
<br/>

## 3. meter 메서드 수정
___
- 새로 추가한 테스트만 고려했을 때 meter 메서드
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    return PasswordStrength.NORMAL;
  }
}
```
위와 같이 했을 경우 첫번째 테스트를 통과하지 못한다.    
첫번째 두번째 테스트 모두 통과하게끔 코드를 작성해야 한다.

- 두 테스트를 모두 고려했을 때
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }
    return PasswordStrength.STRONG;
  }
}
```
이번 테스트는 3개 조건 중 길이가 8개 미만인 조건만 충족하지 않으므로    
길이가 8 미만이면 NORMAL로 하고 그게 아니면 STRONG으로 하면   
첫번째 두번째 테스트 모두 만족한다.
___
<br/>
<br/>

# 세 번째 테스트 : 숫자를 포함하지 않고 나머지 모두 충족
## 1. test code 작성
___
- test code는 두 번째 테스트랑 똑같지만 암호 예시가 달라진다.
- 모든 조건은 만족하고 숫자만 포함되지 않는 예시로 한다.
```java
public class PasswordStrengthMeterTest{
  @Test
  void meetsAllCriteria_Then_Strong(){
    // 첫번재 테스트 수행
  }

  @Test
  void meetsOtherCriteria_except_for_Length_Then_Normal(){
    PasswordStrengthMeter meter = new PasswordStrengthMeter();
    PasswordStrength result = meter.meter("ab12!@A");
    assertEquals(PasswordStrength.NORMAL,result);
  }

  @Test
  meetsOtherCriteria_except_for_number_Then_Normal(){
    PasswordStrengthMeter meter = new PasswordStrengthMeter();
    PasswordStrength result = meter.meter("ab!@ABqwer");
    assertEquals(PasswordStrength.NORMAL,result);
  }
}
```
___
<br/>
<br/>

## 2. meter 메서드 수정
___
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = false;
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
        containsNum = true;
        break;
      }
    }
    if(!containsNum) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    return PasswordStrength.STRONG;
  }
}
```
- 위와 같이 수정하면 1,2,3번째 테스트 모두 통과한다.    
___
<br/>
<br/>

## 3. PasswordStrengthMeter 코드 정리
___
위 코드가 너무 복잡하므로 리펙토링 해보자
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = meetsContainingNumberCriteria(s);
    if(!containsNum) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }
}
```
___
<br/>
<br/>

## 4. test code 정리
___
- test에 중복되는 코드가 있다.
```java
PasswordStrengthMeter meter = new PasswordStrengthMeter();
PasswordStrength result = meter.meter(암호);
assertEquals(PasswordStrength.값,result);
```
- 암호, 값 자리 빼고는 반복이 되므로 따로 메서드를 만들어서 리펙토링하자.
```java
public class PasswordStrengthMeterTest{
  private PasswordStrengthMeter meter = new PasswordStrengthMeter();

  private void assertStrength(String password, PasswordStrength expStr){
    PasswordStrength result = meter.meter(password);
    assertEquals(result, expStr);
  }

  @Test
  void meetsAllCriteria_Then_Strong(){
    assertStrength("ab12!@ab",PasswordStrength.STRONG);

    assertStrength("abc1!!@ab",PasswordStrength.STRONG);
  }

  // 나머지 코드도 위와 같이 바꾼다.
}
```
___
<br/>
<br/>

# 네 번째 테스트 : 값이 없는 경우
- 값이 없을 수도 있다. (에외 상황)
- 값이 빈 문자열일 수도 있다. (예외 상황)
- 예외 상황도 항상 고려해야 된다.

<br/>
<br/>

두 가지 방법으로 예외를 처리할 수 있다.
- IllegalArgumentException 처리
- PasswordStrength.INVALIDE로 자체 처리

<br/>

PasswordStrength.INVALIDE로 처리 선택     
___
<br/>
<br/>

## 1. test code 작성
```java
public class PasswordStrengthMeterTest{
  private PasswordStrengthMeter meter = new PasswordStrengthMeter();

  private void assertStrength(String password, PasswordStrength expStr){
    PasswordStrength result = meter.meter(password);
    assertEquals(result, expStr);
  }
  
  @Test
  void nullInput_the_Invalid(){
    assertStrength(null,PasswordStrength.INVALID);
  }

  @Test
  void emptyInput_Then_Invalid(){
    assertStrength("",PasswordStrength.INVALID);
  }
}
```
- PasswordStrength에 INVALID 값을 추가하지 않아서 오류가 난다.
___
<br/>
<br/>

## 2. PasswordStrength 수정
```java
public enum PasswordStrength{
  STRONG,NORMAL,INVALID
}
```
- 위와 같이 하면 에러가 안난다.
___
<br/>
<br/>

## 3. 빈 값일 때와 null 일 때 모두 처리하도록 meter 수정
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = meetsContainingNumberCriteria(s);
    if(!containsNum) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false; 
  }
}
```
___
<br/>
<br/>

# 다섯 번째 테스트 : 대문자를 포함하지 않고 나머지 조건을 충족하는 경우
## 1. test code 작성

___
```java
public class PasswordStrengthMeterTest{
  private PasswordStrengthMeter meter = new PasswordStrengthMeter();

  private void assertStrength(String password, PasswordStrength expStr){
    PasswordStrength result = meter.meter(password);
    assertEquals(result, expStr);
  }
  
  @Test
  void meetsOtherCriteria_except_for_Uppercase_then_Normal(){
    assertStrength("ab12!@df",PasswordStrength.NORMAL);
  }
}
```
- 대문자가 포함되지 않은 암호 예시 사용
- 위의 test code는 에러가 난다.
- 아직 meter 메서드를 수정하지 않았기 때문에
___
<br/>
<br/>

## 2. meter 메서드 수정
___
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = meetsContainingNumberCriteria(s);
    if(!containsNum) return PasswordStrength.NORMAL;

    // 다섯번째 조건
    boolean containsUpp = false;
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
        containsUpp = true;
        break;
      }
    }
    if(!containsUpp) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }
}
```
___
<br/>
<br/>

## 2-1. meter 메서드 리펙토링
___
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = meetsContainingNumberCriteria(s);
    if(!containsNum) return PasswordStrength.NORMAL;

    // 다섯번째 조건
    boolean containsUpp = meetsContainingUpperCriteria(s)
    if(!containsUpp) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
___
<br/>
<br/>

# 여섯 번째 테스트 : 길이가 8글자 이상 조건만 중촉
- 이제는 한가지 조건만 충족하는 경우들만 테스트 하면 된다.
- 이 때 강도는 WEAK이다.
<br/>
<br/>

## 1. test code 작성
___
```java
@Test
void meetsOnlyLengthCriteria_Then_Weak(){
  assertStrength("abdefghi",PasswordStrength.WEAK);
}
```
- 8글자만 충족하고 대문자도 없고 숫자도 없는 예시를 선택
___
<br/>
<br/>

## 2. PasswordStrength 수정
___
- 강도가 WEAK 이므로 enum 클래스에 WEAK 추가해준다.
```java
public enum PasswordStrength{
  INVALID,WEAK,NORMAL,STRONG
}
```
___
<br/>
<br/>

## 3. test code 실행
___
- test code를 실행시키면 우리가 원했던 WEAK가 아닌 NORMAL이 떠서 에러가 난다.
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    // 두번째 테스트 조건
    if(s.length() < 8){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    boolean containsNum = meetsContainingNumberCriteria(s);
    if(!containsNum) return PasswordStrength.NORMAL;
```
- 네번째 두번째는 넘어가는데
- 세번째 테스트 조건에서 숫자가 없으니 바로 NORMAL을 return 하는 것이다.

### 해결법
- 8 이상일 때 나머지 두 조건이 충족 안할 때는 WEAK을 return하도록 해야 한다.
___
<br/>
<br/>

## 4. meter 수정
___
지금부터 meter 메서드를 두 구역으로 나눌 것이다.      
1. boolean 타입으로 해당 세가지 조건의 충족 여부 확인
2. 조건에 따른 강도 (WEAK,NORMAL,STRONG) 판단 후 reuturn

```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;
    
    // 길이가 8 이상이면 true
    boolean lengthEnough = s.length() >= 8;
    // 대문자 포함이면 true
    boolean containsUpp = meetsContainingUpperCriteria(s)
    // 숫자 포함이면 true
    boolean containsNum = meetsContainingNumberCriteria(s);

//==========================================================

    // 여섯 번째 테스트 조건
    // 길이가 8 이상이고 나머지 조건은 충족 못할 때
    if(lengthEnough && !containsUpp && !containsNum){
      return PasswordStrength.WEAK;
    }

    // 두번째 테스트 조건
    // 8자 이상이 안될 때 (나머지 두 조건은 충족)
    if(!lengthEnough){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    // 숫자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsNum) return PasswordStrength.NORMAL;

    // 다섯번째 조건
    // 대문자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsUpp) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    // 3가지 모두 충족이 되었을 때
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
- 선을 기준으로 위에는 조건 충족 여부
- 밑에는 조건에 따른 return 값 결정
___
<br/>
<br/>

# 숫자 포함 조건만 충족하는 경우
## 1. test code 작성
___
```java
@Test
void meetsOnlyNumCriteria_Then_Weak(){
  assertStrength("12345",PasswordStrength.WEAK);
}
```
- 숫자만 있는 암호 예시 사용
- 대문자와 8자이상 조건 충족 x
___
<br/>
<br/>

## 2. meter 수정
___
```java
// 일곱 번째 테스트 조건
// 숫자만 포함되있고 나머지 두 조건은 충족 못할 때
if(!lengthEnough && !containsUpp && containsNum){
  return PasswordStrength.WEAK;
}
```
- 위의 코드 추가하면 된다.
<br/>
<br/>


```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;
    
    // 길이가 8 이상이면 true
    boolean lengthEnough = s.length() >= 8;
    // 대문자 포함이면 true
    boolean containsUpp = meetsContainingUpperCriteria(s)
    // 숫자 포함이면 true
    boolean containsNum = meetsContainingNumberCriteria(s);

//==========================================================

    // 여섯 번째 테스트 조건
    // 길이가 8 이상이고 나머지 조건은 충족 못할 때
    if(lengthEnough && !containsUpp && !containsNum){
      return PasswordStrength.WEAK;
    }

    // 일곱 번째 테스트 조건
    // 숫자만 포함되있고 나머지 두 조건은 충족 못할 때
    if(!lengthEnough && !containsUpp && containsNum){
      return PasswordStrength.WEAK;
    }

    // 두번째 테스트 조건
    // 8자 이상이 안될 때 (나머지 두 조건은 충족)
    if(!lengthEnough){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    // 숫자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsNum) return PasswordStrength.NORMAL;

    // 다섯번째 조건
    // 대문자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsUpp) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    // 3가지 모두 충족이 되었을 때
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
___
<br/>
<br/>

# 여덟 번째 테스트 : 대문자 포함 조건만 충족
## 1. test code 작성
___
```java
@Test
void meetsOnlyUpperCriteria_Then_Weak(){
  assertStrength("ABZEF",PasswordStrength.WEAK);
}
```
___
<br/>
<br/>

## 2. meter 메서드 수정
___
```java
// 여덟 번째 테스트 조건
// 대문자만 포함되있고 나머지 두 조건은 충족 못할 때
if(!lengthEnough && containsUpp && !containsNum){
  return PasswordStrength.WEAK;
}
```
- 위의 코드 추가하면 된다.
<br/>
<br/>

```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;
    
    // 길이가 8 이상이면 true
    boolean lengthEnough = s.length() >= 8;
    // 대문자 포함이면 true
    boolean containsUpp = meetsContainingUpperCriteria(s)
    // 숫자 포함이면 true
    boolean containsNum = meetsContainingNumberCriteria(s);

//==========================================================

    // 여섯 번째 테스트 조건
    // 길이가 8 이상이고 나머지 조건은 충족 못할 때
    if(lengthEnough && !containsUpp && !containsNum){
      return PasswordStrength.WEAK;
    }

    // 일곱 번째 테스트 조건
    // 숫자만 포함되있고 나머지 두 조건은 충족 못할 때
    if(!lengthEnough && !containsUpp && containsNum){
      return PasswordStrength.WEAK;
    }

    // 여덟 번째 테스트 조건
    // 대문자만 포함되있고 나머지 두 조건은 충족 못할 때
    if(!lengthEnough && containsUpp && !containsNum){
        return PasswordStrength.WEAK;
    }

    // 두번째 테스트 조건
    // 8자 이상이 안될 때 (나머지 두 조건은 충족)
    if(!lengthEnough){
      return PasswordStrength.NORMAL;
    }

    // 세번째 테스트 조건
    // 숫자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsNum) return PasswordStrength.NORMAL;

    // 다섯번째 조건
    // 대문자가 포함되지 않았을 때 (나머지 두 조건은 충족)
    if(!containsUpp) return PasswordStrength.NORMAL;

    // 첫번째 테스트 조건
    // 3가지 모두 충족이 되었을 때
    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
___
<br/>
<br/>

## 4. meter 코드 정리 
___
뭔가 조금 복잡한 느낌이 있다. 좀 더 리펙토링 할 순 없을까?

- 조건 개수를 사용해보는 건 어떨까?
  - 만족하는 조건이 3개면 STRONG
  - 만족하는 조건이 2개면 NORMAL
  - 만족하는 조건이 1개면 WEAK
<br/>
<br/>
<br/>

### 정리 결과 코드
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    // 만족하는 조건 개수 count
    int metCounts = 0;
    if(s.length() >= 8) metCounts++;
    if(meetsContainingNumberCriteria(s)) metCounts++;
    if(meetsContainingUpperCriteria(s)) metCounts++;

    // 만족하는 조건 개수에 따라 강도 return
    if(metCounts == 1) return PasswordStrength.WEAK;
    if(metCounts == 2) return PasswordStrength.NORMAL;

    return PasswordStrength.STRONG;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
- 코드가 정말 간단해졌고
- 조건 개수에 따라 강도를 나누니 가시성도 좋아졌다.
___
<br/>
<br/>

# 아홉 번째 테스트 : 아무 조건도 충족 안 할 때
## 1. test code 작성
```java
public class PasswordStrengthMeterTest{
  // ... 생략
  @Test
  void meetsNoCriteria_Then_Weak(){
    assertStrength("abc",PasswordStrength.WEAK);
  }
}
```
- 대문자 x
- 길이 8 이상 x
- 숫자 x
- 모두 조건이 만족하지 않는 예시다.
___
<br/>
<br/>

## 2. meter 메서드 수정
___
### 해결법
- 조건이 1개 이하면 WEAK return 
- 만족하는 조건 == 0 이면 WEAK return

첫번째 껄로 수정한다면
```java
// 만족하는 조건 개수에 따라 강도 return
if(metCounts <= 1) return PasswordStrength.WEAK;
```
- 원래는 == 이였는데 이하로 수정하면 된다.

___
<br/>
<br/>

# 최종 코드 정리
```java
// 만족하는 조건 개수 count
    int metCounts = 0;
    if(s.length() >= 8) metCounts++;
    if(meetsContainingNumberCriteria(s)) metCounts++;
    if(meetsContainingUpperCriteria(s)) metCounts++;
```

- 위 부분을 정리하면 좀 더 깔끔한 코드가 될 것 같다.
- 위 코드를 따로 메서드로 만들어서 main 코드에서는 호출만 하도록 만들자.

```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    int metCounts = getMetCritieriaCounts(s);

    // 만족하는 조건 개수에 따라 강도 return
    if(metCounts <= 1) return PasswordStrength.WEAK;
    if(metCounts == 2) return PasswordStrength.NORMAL;

    return PasswordStrength.STRONG;
  }

  private int getMetCritieriaCounts(String s){
    // 만족하는 조건 개수 count
    int metCounts = 0;
    if(s.length() >= 8) metCounts++;
    if(meetsContainingNumberCriteria(s)) metCounts++;
    if(meetsContainingUpperCriteria(s)) metCounts++;
    return metCounts;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
- 위 코드처럼 정리하면 처음 개발자가 봤을 때 
  - 암호가 null이거나 빈 문자열이면 암호 강도는 INVALID 이구나
  - 충족하는 규칙 개수를 구하네
  - 충족하는 규칙 개수가 1 이하면 암호 강도가 WEAK이다.
  - 충족하는 규칙 개수가 2이면 암호 강도가 NORMAL이다.
  - 이 외에는 암호 강도가 STRONG이다.   

한번에 알 수 있다.
___
<br/>
<br/>

# 최종 코드
### PasswordStrengthMeter 클래스
```java
public class PasswordStrengthMeter{
  public PasswordStrength meter(String s){
    // 네번째 테스트 조건
    if(s == null || s.Empty()) return PasswordStrength.INVALID;

    int metCounts = getMetCritieriaCounts(s);

    // 만족하는 조건 개수에 따라 강도 return
    if(metCounts <= 1) return PasswordStrength.WEAK;
    if(metCounts == 2) return PasswordStrength.NORMAL;

    return PasswordStrength.STRONG;
  }

  private int getMetCritieriaCounts(String s){
    // 만족하는 조건 개수 count
    int metCounts = 0;
    if(s.length() >= 8) metCounts++;
    if(meetsContainingNumberCriteria(s)) metCounts++;
    if(meetsContainingUpperCriteria(s)) metCounts++;
    return metCounts;
  }

  // 숫자 포함 확인 코드 분리
  private boolean meetsContainingNumberCriteria(String s){
    for(char ch : s.toCharArray()){
      if(ch >= '0' & ch <= '9'){
      return true;
      }
    }
  return false;
  }

  // 대문자 포함 확인 코드 분리
  private boolean meetsContainingUpperCriteria(String s){
    for(char ch : s.toCharArray()){
      if(Character.isUpper(ch)){
      return true;
      }
    }
  return false;
  }
}
```
### PasswordStrength enum 클래스
```java
public enum PasswordStrength{
  INVALID,WEAK,NORMAL,STRONG
}
```
<br/>
<br/>

# 테스트에서 main으로 코드 이동하면 구현 끝
