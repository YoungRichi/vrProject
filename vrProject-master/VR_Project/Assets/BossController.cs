using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BossController : MonoBehaviour
{
    private UnityEngine.AI.NavMeshAgent navComponent;
    public Transform target;
    public float DistanceRun = 4.0f;
 
    public GameObject WinningCondition;

    //=====================================
    public int g_maxHealth = 5;
    public int g_currentHealth;

    public static int playerScore;

    void Start()
    {
        target = GameObject.FindGameObjectWithTag("Player").transform;
        navComponent = this.gameObject.GetComponent<UnityEngine.AI.NavMeshAgent>();

        g_currentHealth = g_maxHealth;
    }

    void Update()
    {
        float dist = Vector3.Distance(target.position, transform.position);
        //run away from player
        if (dist < DistanceRun)
        {
            Vector3 dirtToPlayer = transform.position - target.position;
            Vector3 newPostion = transform.position + dirtToPlayer;

            navComponent.SetDestination(newPostion);
        }

        //======================
        if (g_currentHealth <= 0)
        {
            Destroy(gameObject);
            Instantiate(WinningCondition, transform.position, transform.rotation);
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Bullet")
        {
            Damage(1);
            Debug.Log("Ghost Health: " + g_currentHealth);
            Destroy(other.gameObject);
            playerScore++;

        }
    }

    void Damage(int damageAmount)
    {
        g_currentHealth -= damageAmount;
    }

    void Heal(int healAmount)
    {
        g_currentHealth += healAmount;
    }


}
