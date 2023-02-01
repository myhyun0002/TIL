# XML
## JSON vs XML
___
### JSON
```json
{
    "CSKnowledgeList": [{
          "name": "디자인패턴",
          "difficult": 5
        },
        {
          "name": "네트워크", 
          "difficult": 4
        } 
    ]
}
```
### XML
```xml
<?xml version="1.0" encoding="UTF-8"?>
<CSKnowledgeList>
  <CS>
    <name>디자인패턴</name> <difficult>5</difficult>
  </CS> 
  <CS>
    <name>네트워크</name> <difficult>4</difficult> 
  </CS>
</CSKnowledgeList>
```
___
<br/>
<br/>

## XML 구조
___
- 프롤로그 : xml version과 encoding으로 이루어짐 (보통 utf-8)
```xml
<?xml version="1.0" encoding="UTF-8"?>
```
- 태그
```xml
<cs></cs>
```

___
<br/>
<br/>

## sitemap.xml
___
- xml의 대표적 예시
- 사이트가 큰 경우 링크 연결이 누락될 수 있는 데 방지해줌
```xml
<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
  <url>
    <loc>http://www.example.com/foo.html</loc>
    <lastmod>2018-06-04</lastmod>
  </url> 
  <url>
    <loc>http://www.example.com/abc.html</loc>
    <lastmod>2018-06-04</lastmod>
  </url>
</urlset>
```
___
<br/>

많은 사람들이 api를 구현할 시에 인자 데이터와 응답받는 데이터 형식으로 JSON을 많이 사용하고 있다.  이 글을 쓰는 나조차도 xml은 생각도 안하고 바로 JSON으로 데이터를 주고 받고 있다.  
하지만 웹api에서는 그렇지만 다른 곳에서는 아직까지도 xml을 많이 사용하고 있다.      
그렇다면 JSON의 편리함 뒤에 숨은 XML의 장점은 없을까?
<br/>
<br/>

## XML 장점
___
- json보다 안정성이 좋다.
- 프롤로그에 인코딩 형식을 정의할 수 있어서 다양한 인코딩이 가능하다.
  - 참고로 json은 utf-8만 가능
- 태그 등을 통해 메타데이터를 보여줄 수 있다.
  - (json과 달리 안정성이 뛰어나다고 하는데 모든 블로그에서 똑같은 문구로 되어 있어서 정확하게 알아보고 이 부분은 써야 겠다.)