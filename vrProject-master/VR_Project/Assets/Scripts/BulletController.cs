using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletController : MonoBehaviour
{
    public float timer = 4;
    public Rigidbody Projectile;
    [SerializeField] Transform Spawn;
    public int force;
	public float flightSpd = 3.0f; //control bullet projectile speed; multiplicative
	public bool fireMode = false;

    void Update()
    {
		//toggle fire mode
		if (Input.GetKeyUp(KeyCode.Q)){
			if (fireMode == false){
				fireMode = true;
				Debug.Log("Switched to burst fire");
			}
			else if (fireMode == true){
				fireMode = false;
				Debug.Log("Switched to semi auto");
			}
		}
        if (Input.GetButtonDown("Fire1"))
        {
			//semi auto
			if (fireMode == false){
	            Rigidbody bullet;
				bullet = Instantiate(Projectile, Spawn.position, Spawn.rotation);
	            GetComponent<AudioSource>().Play();
	            bullet.AddForce(Spawn.forward * force * flightSpd);
	            Destroy(bullet.gameObject, 1f);
			}
			if (fireMode == true){
				int lewps = 0;
				while (lewps <= 3){
					Rigidbody bullet;
					bullet = Instantiate(Projectile, Spawn.position, Spawn.rotation);
					GetComponent<AudioSource>().Play();
					bullet.AddForce(Spawn.forward * force * flightSpd);
					Destroy(bullet.gameObject, 1f);
					lewps++;
				}
			}
        }
    }


}

