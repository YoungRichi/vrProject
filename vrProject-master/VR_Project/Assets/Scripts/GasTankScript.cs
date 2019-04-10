using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GasTankScript : MonoBehaviour
{
    private float speed = .6f;
    private float rotSpeed = 6.0f;
    private Vector3 p1; //= new Vector3(2, 8, 38);
    private Vector3 p2;// = new Vector3(2, 9, 38);

    private void Start()
    {
        p1 = transform.position;
        p1.y = 3f;
        p2 = transform.position;
        p2.y = 7f;
    }

    void Update()
    {
        transform.position = Vector3.Lerp(p1, p2, Mathf.PingPong(Time.time * speed, 1.0f));
        transform.RotateAround(transform.position, (Vector3.up), Time.deltaTime * 90f);
        // transform.RotateAround(Vector3.up * rotSpeed, 30.0f);
    }
}
