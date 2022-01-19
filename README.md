# AsynciO (System Programming) 동기_비동기 장치 IO

파일저장 동기, 비동기로 실행하기

## 핵심  
WriteFile  
WriteFileEx  

ReadFile  
ReadFileEx  

**WriteFile은 동기 비동기 다 사용 가능하다**
**기본적으로 파일은 동기로 저장하고 읽어진다**  
**Ex는 비동기로 사용할 때 사용한다**  
**FILE_FLAG_OVERLAPPED 비동기로 개방**  
