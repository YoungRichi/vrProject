using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    public int maxHealth = 5;
    public int currentHealth;

    public Rigidbody Projectile;
    public Transform Spawn;
    public int force = 1000;
    public GameObject BulletSpawn;
    public GameObject Bullet;

    public GameObject messagePanel;
    public GameObject victoryPanel;


    public Image healthBar;
    private float healthPercentage;

    public static int currentScore;

    void Start()
    {
        currentHealth = maxHealth;
        //Debug.Log("currentHealth: "+ currentHealth);
        //Heal(1);
    }

    void Update()
    {
        HandleInput();

        healthPercentage = (float) currentHealth / (float) maxHealth;
        healthBar.fillAmount = healthPercentage;

       // txtScore.text = string.Format()


        if (currentHealth == 0)
        {
            //Destroy(gameObject);
            Debug.Log("Game Over");
            messagePanel.SetActive(true);
        }

        //Debug.Log(currentScore);

    }

    void HandleInput()
    {
        if (Input.GetButtonDown("Fire1"))
        {
            Rigidbody bullet;
            bullet = Instantiate(Projectile, Spawn.position, Spawn.rotation);
            bullet.AddForce(Spawn.forward * 1000f);
            Destroy(bullet.gameObject, 1f);
            //Debug.Log("Bullet Destroyed");
        }
        

    }

    public void Damage(int damageAmount)
    {
        currentHealth -= damageAmount;
    }

    public void Heal(int healAmount)
    {
        currentHealth += healAmount;
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Enemy") 
        {
            Damage(1);
        }
        if (other.tag == "Key")
        {
            currentScore += 100;
            Destroy(other.gameObject);
            victoryPanel.SetActive(true);
        }
    }

}
