import React from 'react'
import { Link } from 'react-router-dom'

const Navbar = () => {
  return (
    <div>
      <nav className="navbar navbar-expand-lg bg-body-tertiary">
        <div className="container">
          <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span className="navbar-toggler-icon" />
          </button>
          <div className="collapse navbar-collapse" id="navbarSupportedContent">
            <ul className="navbar-nav me-auto mb-2 mb-lg-0 gap-5">
              <li className="nav-item">
                <a className="nav-link active" aria-current="page" href="/">BookMyShow</a>
              </li>
              <li className="nav-item">
                <Link to={"/movielist"} className='nav-link'>Movie List</Link>
              </li>
              <li className="nav-item">
                <form className="d-flex" role="search">
                  <input className="form-control me-2" type="search" placeholder="Enter Movie name" aria-label="Search" />
                  <button className="btn btn-outline-success" type="submit">Search</button>
                </form>
              </li>
            </ul>
          </div>
          <a className="navbar-brand" href="#"><i className="ri-user-line" /></a>
          <div className="ps-2">Sign Out <i className="ri-logout-box-r-line fs-5 ps-2" /></div>
        </div>
      </nav>

    </div>
  )
}

export default Navbar