using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    public float deathDistance = 0.5f;
    public float distanceAway;
    public Transform thisObject;
    public Transform target;
    private UnityEngine.AI.NavMeshAgent navComponent;

    public int g_maxHealth = 3;
    public int g_currentHealth;

    public static int playerScore;



    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.FindGameObjectWithTag("Player").transform;
        navComponent = this.gameObject.GetComponent<UnityEngine.AI.NavMeshAgent>();

        g_currentHealth = g_maxHealth;

    }

    // Update is called once per frame
    void Update()
    {
        
        if (g_currentHealth <= 0)
        {
            Destroy(gameObject);
        }

        //============follow===============
        float dist = Vector3.Distance(target.position, transform.position);
        
        if(target)
        {
            navComponent.SetDestination(target.position);
        }

        else
        {
            if (target = null)
            {
                target = this.gameObject.GetComponent<Transform>();
            }
            else
            {
                target = GameObject.FindGameObjectWithTag("Player").transform;
            }
        }
        if (dist <= deathDistance)
        {
            //kill player.
        }


    }

    //======================================================================================
    void OnCollisionEnter(Collision other)
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
