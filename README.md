# 42Cursus-Minishell


- 프롬프트 표시
- 작업 이력 표시
- 올바른 실행 파일을 검색하고 실행합니다(PATH 변수를 기준으로 하거나 상대 경로 또는 절대 경로를 사용).
- 전역 변수를 두 개 이상 사용하지 않기.
- \(백슬래시) 또는 ;(세미콜론)과 같이 Subject에서 필요하지 않은 닫히지 않은 따옴표나 특수 문자 해석x.
- '(작은따옴표) 처리는 셸이 따옴표로 묶인 시퀀스의 메타 문자를 해석하지 못하도록 해야 함.
- '(큰따옴표)처리는 셸이 따옴표로 묶인 시퀀스의 메타 문자를 $(달러 기호)를 제외하고 해석하지 못하도록 해야 함.


- Implement redirections: 리다이렉션을 구현
    - < should redirect input : 입력 리다이렉션
    - \> should redirect output : 출력 리다이렉션
    - << : 구분 기호를 지정한 다음 구분 기호가 포함된 줄이 보일 때까지 입력을 읽어야 한다. (However, it doesn’t have to update the history!)
    - \>> : 추가 모드에서 출력을 리다이렉션
    
- pipe(| 문자)를 구현
  파이프라인에서 각 명령의 출력은 파이프를 통해 다음 명령의 입력에 연결된다.
  
- 환경 변수($ 뒤에 문자 시퀀스)를 처리
- $? 는 가장 최근에 실행된 포그라운드 파이프라인의 종료 상태로 확장되어야 한다.

- bash에서와 같이 작동해야 하는 ctrl-C, ctrl-D 및 ctrl-\를 처리
- In interactive mode
    - ctrl-C displays a new prompt on a new line.
ctrl -C 는 새 줄에 새 프롬프트를 표시한다.
    - ctrl-D exits the shell.
ctrl-D 는 셸을 종료한다.
    - ctrl-\ does nothing.
ctrl-\는 아무 작업도 수행하지 않는다.

- builtin functions 구현
    - echo with option -n
옵션 -n이 있는 echo
    - cd with only a relative or absolute path 
    상대경로 혹은 절대경로로가 있는 cd
    - pwd with no options
    옵션 없는 pwd
    - export with no options
    export
    - unset with no options
    unset
    - env with no options or arguments
    옵션이나 인수가 없는 env
    - exit with no options
    옵션 없는 exit
