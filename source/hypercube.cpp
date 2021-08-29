#include "../include/hypercube.h"

hypercube::hypercube():default_hypercube4D {
		{+1.0, +1.0, +1.0, +1.0},
		{-1.0, +1.0, +1.0, +1.0},
		{+1.0, -1.0, +1.0, +1.0},
		{-1.0, -1.0, +1.0, +1.0},
		
		{+1.0, +1.0, -1.0, +1.0},
		{-1.0, +1.0, -1.0, +1.0},
		{+1.0, -1.0, -1.0, +1.0},
		{-1.0, -1.0, -1.0, +1.0},
		
		{+1.0, +1.0, +1.0, -1.0},
		{-1.0, +1.0, +1.0, -1.0},
		{+1.0, -1.0, +1.0, -1.0},
		{-1.0, -1.0, +1.0, -1.0},
		
		{+1.0, +1.0, -1.0, -1.0},
		{-1.0, +1.0, -1.0, -1.0},
		{+1.0, -1.0, -1.0, -1.0},
		{-1.0, -1.0, -1.0, -1.0}	
	},
    default_hypercube3D {
        {+1.0, +1.0, +1.0},
        {-1.0, +1.0, +1.0},
        {+1.0, -1.0, +1.0},
        {-1.0, -1.0, +1.0},

        {+1.0, +1.0, +1.0},
        {-1.0, +1.0, +1.0},
        {+1.0, -1.0, +1.0},
        {-1.0, -1.0, +1.0},

        {+1.0, +1.0, -1.0},
        {-1.0, +1.0, -1.0},
        {+1.0, -1.0, -1.0},
        {-1.0, -1.0, -1.0},

        {+1.0, +1.0, -1.0},
        {-1.0, +1.0, -1.0},
        {+1.0, -1.0, -1.0},
        {-1.0, -1.0, -1.0}
    },
    hypercube4D {
		{+1.0, +1.0, +1.0, +1.0},
		{-1.0, +1.0, +1.0, +1.0},
		{+1.0, -1.0, +1.0, +1.0},
		{-1.0, -1.0, +1.0, +1.0},
		
		{+1.0, +1.0, -1.0, +1.0},
		{-1.0, +1.0, -1.0, +1.0},
		{+1.0, -1.0, -1.0, +1.0},
		{-1.0, -1.0, -1.0, +1.0},
		
		{+1.0, +1.0, +1.0, -1.0},
		{-1.0, +1.0, +1.0, -1.0},
		{+1.0, -1.0, +1.0, -1.0},
		{-1.0, -1.0, +1.0, -1.0},
		
		{+1.0, +1.0, -1.0, -1.0},
		{-1.0, +1.0, -1.0, -1.0},
		{+1.0, -1.0, -1.0, -1.0},
		{-1.0, -1.0, -1.0, -1.0}	
	},
    hypercube3D {
        {+1.0, +1.0, +1.0},
        {-1.0, +1.0, +1.0},
        {+1.0, -1.0, +1.0},
        {-1.0, -1.0, +1.0},

        {+1.0, +1.0, +1.0},
        {-1.0, +1.0, +1.0},
        {+1.0, -1.0, +1.0},
        {-1.0, -1.0, +1.0},

        {+1.0, +1.0, -1.0},
        {-1.0, +1.0, -1.0},
        {+1.0, -1.0, -1.0},
        {-1.0, -1.0, -1.0},

        {+1.0, +1.0, -1.0},
        {-1.0, +1.0, -1.0},
        {+1.0, -1.0, -1.0},
        {-1.0, -1.0, -1.0}
    }
{}