using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public int maxHealth = 5;
    public int currentHealth;

    public Rigidbody Projectile;
    public Transform Spawn;
    public int force = 1000;
    public float timer = 4;


    // Start is called before the first frame update
    void Start()
    {
        currentHealth = maxHealth;
    }

    // Update is called once per frame
    void Update()
    {
        HandleInput();
        currentHealth = maxHealth;

        if (currentHealth == 0)
        {
            Debug.Log("Game Over");
        }


    }

    void HandleInput()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            Rigidbody bullet;
            bullet = Instantiate(Projectile, Spawn.position, Spawn.rotation);
            bullet.AddForce(Spawn.forward * 1000f);


            //timer -= 1.0f * Time.deltaTime;
            //if (timer >= 0)
            //{
            //    GameObject.Destroy(bullet);
            //}

        }
    }
}
