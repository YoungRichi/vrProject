using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RadialBulletController : MonoBehaviour
{
    [Header("Projectile Settings")]
    public int numberofProjectiles;
    public float projectileSpeed;
    public GameObject ProjectilePrefab;
    public AudioClip laser;
    public AudioClip ready;
    AudioSource audioSource;
    public float cooldown = 5;
    public float cooldownTimer;

    private Vector3 startPoint;
    private const float radius = 1F;



    void Start()
    {
        audioSource = GetComponent<AudioSource>();
    }
    void Update()
    {
        if (cooldownTimer > 0)
        {
            cooldownTimer -= Time.deltaTime;
        }
        if (cooldownTimer < 0)
        {
            cooldownTimer = 0;
            audioSource.PlayOneShot(ready, 0.1F);

        }


        if (Input.GetKeyDown(KeyCode.Space) && cooldownTimer == 0)
        {
            startPoint = transform.position; //Player's location
            SpawnProjectile(numberofProjectiles);

            cooldownTimer = cooldown;
        }
    }

    private void SpawnProjectile(int _numberOfProjectiles)
    {
        float angleStep = 360f / _numberOfProjectiles; //come from all possible angles
        float angle = 0f;

        for (int i =0; i <= _numberOfProjectiles - 1; i++ )
        {
            audioSource.PlayOneShot(laser, 0.1F);
            //Direction
            float projectileDirXPosition = startPoint.x + Mathf.Sin((angle * Mathf.PI) / 180) * radius;
            float projectileDirYPosition = startPoint.y + Mathf.Cos((angle * Mathf.PI) / 180) * radius;

            Vector3 projectileVector = new Vector3(projectileDirXPosition, projectileDirYPosition, 0);
            Vector3 projectileMoveDirection = (projectileVector - startPoint).normalized * projectileSpeed;

            GameObject tmpObj = Instantiate(ProjectilePrefab, startPoint, Quaternion.identity);
            tmpObj.GetComponent<Rigidbody>().velocity = new Vector3(projectileMoveDirection.x, 0, projectileMoveDirection.y);
            

            angle += angleStep;

            Destroy(tmpObj, 1f);
        }
    }
}
