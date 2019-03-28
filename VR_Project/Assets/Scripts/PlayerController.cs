using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Audio;

public class PlayerController : MonoBehaviour
{
    public float maxHealth = 5;
    public float currentHealth;
    public float damageCoef = 0.001f;

    public Rigidbody Projectile;
    public Transform Spawn;
    public int force;
    public GameObject BulletSpawn;
    public GameObject Bullet;

    public GameObject messagePanel;
    public GameObject victoryPanel;




    public Image healthBar;
    private float healthPercentage;

    public static int currentScore;
    private bool bleeding = false;
    

    [SerializeField] GameObject Door;
    void Start()
    {
        currentHealth = maxHealth;
        //AudioSource audio = GetComponent<AudioSource>();
        //Debug.Log("currentHealth: "+ currentHealth);
        //Heal(1);
    }

    void Update()
    {
        //HandleInput();

        healthPercentage = (float) currentHealth / (float) maxHealth;
        healthBar.fillAmount = healthPercentage;

       // txtScore.text = string.Format()


        if (currentHealth <= 0)
        {
            Time.timeScale = 0;
            //Destroy(gameObject);
            Debug.Log("Game Over");
            messagePanel.SetActive(true);
            //Destroy(this.gameObject);
            
        }

        if(bleeding == true)
        {
            Damage(damageCoef);
        }
     

    }

    public void Damage(float damageAmount)
    {
        currentHealth -= damageAmount;
    }

    public void Heal(float healAmount)
    {
        currentHealth += healAmount;
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Enemy") 
        {
            Damage(1);
        }
        if (other.tag == "Win")
        {
            currentScore += 100;
            Destroy(other.gameObject);
            victoryPanel.SetActive(true);
        }
        if (other.tag == "Key")
        {
            Destroy(other.gameObject);
            Door.SetActive(false);

        }
        if (other.tag == "DoorScan")
        {
            Door.SetActive(true);
            bleeding = true;
        }
    }

}
