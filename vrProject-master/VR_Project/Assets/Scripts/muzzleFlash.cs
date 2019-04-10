﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class muzzleFlash : MonoBehaviour
{
	ParticleSystem mf;

	void Start(){
		mf = GetComponent<ParticleSystem>();
	}

    // Update is called once per frame
    void Update()
    {
		if (Input.GetMouseButtonDown(0)){
			Debug.Log("muzzle flash");
			mf.Play();
		}
    }
}