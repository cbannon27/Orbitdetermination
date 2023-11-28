This is my Orbit Visualizer and Determination program

When choosing Mode 1: Orbit Visualizer
	the SemiMajorAxis represents the length of the longest radius from the focus of the orbit
	the Eccentricity represents the degree to which the orbit is elliptical (0 being circular and .99 being incredibly elliptical)
	the	Eccentricity cannot less than 0 as an orbit of such eccentricity would not make physical sense
	The planet that the user selected will be shown in blue with the orbit. any orbit that intersects with its planet is not a "valid" orbit as it will crash into the planet
	when graphing a hyperbolic orbit, the asymptotes of the hyperbola will also be shown in green.
When choosing Mode 2: Orbit Determination
	the program asks the user to input components for 3 distance vectors representing distance from focus of orbit to spacecraft
	In order to show the programs efficacy, a set of tester vectors is given.
		copy and paste these values as is, directly into the prompt
			orbit 1 (Circular)
		r1:	3457.9 456.51 -6006.4
		r2:	3482.6 479 -5990.6
		r3:	3507.3 501.47 -5974.6
		\
			orbit 2 (Ellipse)
		r1:	7943.6 7659.6 6412.1
		r2:	7928.3 7663.9 6458.1
		r3:	7912.8 7668.1 6504
		\
			orbit 3 (Hyperbola)
		r1:	-884.5 4073.1 14345
		r2:	-916.91 4050.9 14347
		r3:	-949.3 4028.6 14348