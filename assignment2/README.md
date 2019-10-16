# Assignment 2

***

## Solitaire

Generate a set of cards from {K,Q,J,10,9,8,7,6,5,4,3,2,A} in random order(No repetition) and put it into an array, then start to draw them out from K to A(You can only draw out a card from the front of the array), if the card at the front of the array is not the one to draw out, put it at the end of the array.

Stop until all the cards have been drawn out.

Print out the state of your cards every time you draw out a card or you put a card to the end of the array.

### Algorithm

First, record the first element as `chosen`, and left shift all the other elements once.

Check if `chosen` equals to the number we want to draw.
If they are equal to each other, draw `chosen`, or put `chosen` to the end of array.
