# SkateBoardSimulation

Developed with Unreal Engine 5

1.Movement Functionality - I start working within blank project, and create character class. made some functionality MoveRight/MoveForward TurnRate/LookUpRate and
Turn/LookUp.
First thing first, code MoveForward and MoveRight and added callbacks to the playerinputcomponent. added axis mappings to the project settings. exact the same picture to Turnrate and turn as well as lookuprate and lookUp.

2.Animations. I download free character from mixamo (x- bot) and 2 different animations (idle, skateboarding)
unfortunately skateboarding animation didn't have in place function. (So I opened blender removed x y z location from this animation and reduced the frames) after that I implemented to my unreal and loop it.
created animinstance class from cpp and coded speed isinair and accelerating variables. based on that class created animation blueprint-> call that cpp function in event graph. and in anim graph created locomotion with logic (idle and skateboarding as well as jumping) used blend mode per bone, and implemented that animmontage to my slow down function. when we are pressing Q button from last second we are playing that animmontage which seems like we are falling.

3. Speed up and slow down. I made that with blueprints and first category my code is working based on the character movement changes with node(set timer by event). on this we have time duration
second category we are increasing and decreasing speed
with float variable which is lerping from timeline and seting global time. this code does not have duration.

4. I made 4 different UI and they are interacting between each other. we have main menu, pause menu, settings, and also score system which increases when we are jumping obstacles.

5.obstacles. I made simple blueprint actor class and begin overlap simply casts to our skateboard guy and adds points to variable.

6. level design I just download city park environment and designed my 2 different obstacles.

animation took me like 4-5 hour due to i needed to get smooth transition between them. but i tried to fix it with curves.

ui - 1 hour
movement functionally- 1 hour
slow down speed up -  2 hour
points system - 30 minutes
design - it was 3-4 hours
animation - 4 hours

E-SpeedUp
Q-SlowDown
1-Speedup
2-NormalSpeed
3-SlowDown
P-Pause Menu

