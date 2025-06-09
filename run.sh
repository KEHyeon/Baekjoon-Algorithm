#!/bin/bash
if [ -z "$1" ]; then
  echo "❗ 사용법: ./run.sh 파일이름.cpp"
  exit 1
fi

SRC="$1"
BIN="main"

clang++ -std=c++17 -O2 -Wall -Wextra "$SRC" -o "$BIN"

if [ $? -eq 0 ]; then
  echo "✅ 컴파일 성공! 실행 중..."
  echo "-----------------------------"
  ./"$BIN"
  echo  # <- 여기에 줄바꿈 추가
else
  echo "❌ 컴파일 실패"
fi
