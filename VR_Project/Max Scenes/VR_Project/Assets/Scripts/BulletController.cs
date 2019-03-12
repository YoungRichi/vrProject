using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletController : MonoBehaviour
{
    public float timer = 4;
    public Rigidbody Projectile;
    [SerializeField] Transform Spawn;
    public int force;


    void Update()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            Rigidbody bullet;
            bullet = Instantiate(Projectile, Spawn.position, Spawn.rotation);
            GetComponent<AudioSource>().Play();
            bullet.AddForce(Spawn.forward * force);
            Destroy(bullet.gameObject, 1f);
        }
    }


}

