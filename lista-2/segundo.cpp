/*
UFMT - ProgII
Aluno: Gabriel Nunes
*/

#include <iostream>
using namespace std;

int main() {
  string str1, str2;
  int primeira[26] = {0};
  int segunda[26] = {0};
  int character = 0, flag = 0;

  cout << "Primeira String: ";
  cin >> str1;
  cout << "Segunda String: ";
  cin >> str2;

  while (str1[character] != '\0') {
    primeira[str1[character] - 'a']++;
    character++;
  }

  character = 0;
  while (str2[character] != '\0') {
    segunda[str2[character] - 'a']++;
    character++;
  }

  for (character = 0; character < 26; character++) {
    if (primeira[character] != segunda[character]) {
      flag = 1;
      break;
    }
  }

  if (flag == 0) {
    cout << "Strings sao um anagrama";
  } else {
    cout << "Strings nao sao um anagrama";
  }
  return 0;
}
