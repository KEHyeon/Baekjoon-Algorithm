#!/bin/bash
if [ -z "$1" ]; then
  echo "❗ 사용법: ./run.sh 파일이름.cpp"
  exit 1
fi

SRC="$1"
BIN="main"

# 컴파일: libc++를 명시적으로 사용하고, 런타임 라이브러리 경로를 설정
clang++ -std=c++17 -stdlib=libc++ -O2 -Wall -Wextra "$SRC" -o "$BIN"

if [ $? -eq 0 ]; then
  echo "✅ 컴파일 성공! 실행 중..."
  echo "-----------------------------"
  
  # 런타임 환경에서 libc++ 경로를 명시적으로 설정
  DYLD_LIBRARY_PATH="/usr/lib:/usr/local/lib" ./"$BIN"
  
  echo  # <- 여기에 줄바꿈 추가
else
  echo "❌ 컴파일 실패"
fi