# DynoGuy
DynoGuy is an endless runner game where the player's dinosaur has to jump over cacti as he runs away from inevitable extinction!

In this implementation, the dinosaur is controlled by a machine learning AI, which learns how to jump over the cacti with Q-learning.

See it in action here: 

[![ScreenShot](https://drive.google.com/thumbnail?id=0B9y-KG5ruJficFF2WWF0eTNaVk0&authuser=0&v=1463422490251&sz=w320-h200-p-k-nu)](https://drive.google.com/open?id=0B9y-KG5ruJficFF2WWF0eTNaVk0)

When the dinosaur intersects the cacti (and becomes an @), it represents a player loss, or failure. 
A negative incentive is updated in the QArray, and thus the dinosaur learns how to jump over the cacti after a few trials. 

## Getting Started
Download the .cc and .h files and compile the .cc files to run the AI. 

## Authors
David Woo and Peyman Gardideh

## Acknowledgments
Inspired by Google Chrome's T-Rex Runner


